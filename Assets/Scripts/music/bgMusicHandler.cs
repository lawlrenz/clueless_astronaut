using UnityEngine;
using System.Collections;

public class bgMusicHandler : MonoBehaviour {

	private static bgMusicHandler instance = null;
	
	public static bgMusicHandler Instance{
		get { return instance; }
	}

	// Use this for initialization
	void Start () {
		if (instance != null && instance != this) {
			Destroy (this.gameObject);
			return;
		} else {
			instance = this;
		}
		DontDestroyOnLoad (this.gameObject);
	}
	
	// Update is called once per frame
	void Update () {
	}
}
