using UnityEngine;
using System.Collections;

public class patrolItem : MonoBehaviour {

	private float xLeft;
	private float xRight;
	private float yLeft;
	private float yRight;
	private float movSpeed;

	private Vector2 startingPos;

	// Use this for initialization
	void Start () {
		startingPos.x = this.transform.x;
		startingPos.y = this.transform.y;
		
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
